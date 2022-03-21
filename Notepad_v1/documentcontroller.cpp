#include "documentcontroller.h"
#include <QQmlFile>
#include <QMimeType>
#include <QMimeDatabase>
#include <QTextCodec>
#include <QFileInfo>

QTextDocument *DocumentController::m_qtextDocument = nullptr;
DocumentController::DocumentController(QObject *parent)
    : QObject(parent)
{

}

QQuickTextDocument *DocumentController::notepadDoc() const
{
    return m_notepadDoc;
}

void DocumentController::SetnotepadDoc(QQuickTextDocument *newNotepadDoc)
{
    m_notepadDoc = newNotepadDoc;
    emit notepadDocChanged();
}

QTextDocument *DocumentController::qtextDocument() const
{
    if(m_notepadDoc == nullptr)
    {
        m_qtextDocument = nullptr;
    }else{
        m_qtextDocument = m_notepadDoc->textDocument();
    }
    return m_qtextDocument;
}

void DocumentController::setFormatting(const QTextCharFormat &textFormat)
{
    QTextCursor curCursor = textCursor();
    if(!curCursor.isNull())
    {
        if(!curCursor.hasSelection())
        {
            curCursor.select(QTextCursor::WordUnderCursor);
        }
        curCursor.mergeCharFormat(textFormat);
    }
    resetFormatting();
}

void DocumentController::setQtextDocument(QTextDocument *newQtextDocument)
{
    m_qtextDocument = newQtextDocument;
}

void DocumentController::resetFormatting()
{
    emit fontSizeChanged();
    emit textColorChanged();
    emit fontFamilyChanged();
    emit boldChanged();
    emit italicChanged();
    emit underlineChanged();
    emit isUndoAvailableChanged();
    emit isRedoAvailableChanged();
}

QTextCursor DocumentController::textCursor() const
{
    m_qtextDocument = qtextDocument();
    if(!m_qtextDocument)
    {
        return QTextCursor();
    }

    QTextCursor curCursor = QTextCursor(m_qtextDocument);
    if(m_selectionStart != m_selectionEnd)
    {
        curCursor.setPosition(m_selectionStart);
        curCursor.setPosition(m_selectionEnd, QTextCursor::KeepAnchor);
    }
    else
    {
        curCursor.setPosition(m_cursorPosition);
    }
    return curCursor;
}

QTextDocument *DocumentController::getQtextDocument() const
{
    if(m_notepadDoc == nullptr)
    {
        m_qtextDocument = nullptr;
    }
    else
    {
        m_qtextDocument = m_notepadDoc->textDocument();
    }
    return m_qtextDocument;
}

void DocumentController::openFile(const QUrl &fileUrl)
{
    if(fileUrl.isEmpty()) return;
    const QString filename = QQmlFile::urlToLocalFileOrQrc(QUrl(fileUrl));

    if(QFile::exists(filename))
    {
        QMimeType mimeType = QMimeDatabase().mimeTypeForFile(filename);
        QFile fileObj(filename);

        if(fileObj.open(QFile::ReadOnly))
        {
            QByteArray content = fileObj.readAll();
            m_qtextDocument = m_notepadDoc->textDocument();

            if(m_qtextDocument)
            {
                if(mimeType.inherits("text/markdown"))
                {
                    emit fileContentLoaded(QString::fromUtf8(content), Qt::MarkdownText);
                }
                else
                {
                    QTextCodec *code = QTextCodec::codecForHtml(content);
                    emit fileContentLoaded(code->toUnicode(content), Qt::AutoText);
                }
                m_qtextDocument->setModified(false);
            }
        }
    }
    m_currentFileUrl= fileUrl;
    emit curFileNameChanged();
}

bool DocumentController::saveContent()
{
    if(m_currentFileUrl.isEmpty() || m_notepadDoc == nullptr)
    {
        return false;
    }

    m_qtextDocument = m_notepadDoc->textDocument();
    const QString curfilePath = m_currentFileUrl.toLocalFile();
    const bool isHtml = QFileInfo(curfilePath).suffix().contains(QLatin1String("htm"));

    QFile fileObj(curfilePath);
    if(fileObj.open(QFile::WriteOnly))
    {
        if(isHtml)
        {
            fileObj.write(m_qtextDocument->toHtml().toUtf8());
        }
        else
        {
            fileObj.write(m_qtextDocument->toPlainText().toUtf8());
        }
        fileObj.close();
    }
    return true;
}

bool DocumentController::saveAs(const QUrl &fileUrl)
{
    if(m_currentFileUrl.isEmpty() || m_notepadDoc == nullptr)
    {
        return false;
    }

    m_qtextDocument = m_notepadDoc->textDocument();
    const QString curfilePath = fileUrl.toLocalFile();
    const bool isHtml = QFileInfo(curfilePath).suffix().contains(QLatin1String("htm"));

    QFile fileObj(curfilePath);
    if(fileObj.open(QFile::WriteOnly))
    {
        if(isHtml)
        {
            fileObj.write(m_qtextDocument->toHtml().toUtf8());
        }
        else
        {
            fileObj.write(m_qtextDocument->toPlainText().toUtf8());
        }
        fileObj.close();
        m_currentFileUrl = fileUrl;
    }
    emit curFileNameChanged();
    return true;
}

void DocumentController::createFile(const QUrl &fileUrl)
{
    if(fileUrl.isEmpty()) return;

    const QString filename = QQmlFile::urlToLocalFileOrQrc(QUrl(fileUrl));
    QFile fileObj(filename);
    fileObj.open(QFile::WriteOnly);
    fileObj.write("");
    fileObj.close();
    QMimeType mimeType = QMimeDatabase().mimeTypeForFile(filename);
    if(fileObj.open(QFile::ReadOnly))
    {
        QByteArray content = fileObj.readAll();
        m_qtextDocument = m_notepadDoc->textDocument();

        if(m_qtextDocument)
        {
            if(mimeType.inherits("text/markdown"))
            {
                emit fileContentLoaded(QString::fromUtf8(content), Qt::MarkdownText);
            }
            else
            {
                emit fileContentLoaded(QString::fromUtf8(content), Qt::MarkdownText);
            }
            m_qtextDocument->setModified(false);
        }
    }
    m_currentFileUrl = fileUrl;
    emit curFileNameChanged();
}

int DocumentController::cursorPosition() const
{
    return m_cursorPosition;
}

void DocumentController::setCursorPosition(int newCursorPosition)
{
    if (m_cursorPosition == newCursorPosition)
        return;
    m_cursorPosition = newCursorPosition;
    resetFormatting();
    emit cursorPositionChanged();
}

int DocumentController::selectionStart() const
{
    return m_selectionStart;
}

void DocumentController::setSelectionStart(int newSelectionStart)
{
    if (m_selectionStart == newSelectionStart)
        return;
    m_selectionStart = newSelectionStart;
    resetFormatting();
    emit selectionStartChanged();
}

int DocumentController::selectionEnd() const
{
    return m_selectionEnd;
}

void DocumentController::setSelectionEnd(int newSelectionEnd)
{
    if (m_selectionEnd == newSelectionEnd)
        return;
    m_selectionEnd = newSelectionEnd;
    resetFormatting();
    emit selectionEndChanged();
}

const QColor &DocumentController::textColor() const
{
    QTextCursor curCursor = textCursor();
    if(curCursor.isNull())
    {
        return QColor(Qt::black);
    }

    QTextCharFormat textFormat = curCursor.charFormat();
    return textFormat.foreground().color();
}

void DocumentController::setTextColor(const QColor &newTextColor)
{
    QTextCursor curCursor = textCursor();
    QTextCharFormat textFormat;
    if(!curCursor.isNull())
    {
        textFormat = curCursor.charFormat();

        textFormat.setForeground(QBrush(newTextColor));
    }
    setFormatting(textFormat);
    emit textColorChanged();
}

int DocumentController::fontSize() const
{
    QTextCursor curCursor = textCursor();
    if(curCursor.isNull())
    {
        return 0;
    }
    QTextCharFormat textFormat = curCursor.charFormat();
    return textFormat.font().pointSize();
}

void DocumentController::setFontSize(int newFontSize)
{
    if(newFontSize <= 0)
    {
        return;
    }
    QTextCursor curCursor = textCursor();
    if(curCursor.isNull())
    {
        return;
    }
    if(!curCursor.hasSelection())
    {
        curCursor.select(QTextCursor::WordUnderCursor);
    }
    if(curCursor.charFormat().property(QTextFormat::FontPointSize).toInt() == newFontSize)
    {
        return;
    }
    QTextCharFormat textFormat;
    textFormat.setFontPointSize(newFontSize);
    setFormatting(textFormat);
    emit fontSizeChanged();
}

const QString DocumentController::fontFamily() const
{
    QTextCursor curCursor = textCursor();
    if(!curCursor.isNull())
    {
        return QString();
    }
    QTextCharFormat textFormat = curCursor.charFormat();
    return textFormat.font().family();
}

void DocumentController::setFontFamily(const QString &newFontFamily)
{
    QTextCharFormat textFormat;
    textFormat.setFontFamily(newFontFamily);
    setFormatting(textFormat);
    emit fontFamilyChanged();
}

bool DocumentController::bold() const
{
    QTextCursor curCursor = textCursor();
    if(curCursor.isNull())
    {
        return false;
    }
    return curCursor.charFormat().fontWeight() == QFont::Bold;
}

void DocumentController::setBold(bool newBold)
{
    QTextCharFormat textFormat;
    textFormat.setFontWeight(newBold? QFont::Bold : QFont::Normal);
    setFormatting(textFormat);
    emit boldChanged();
}

bool DocumentController::italic() const
{
    QTextCursor curCursor = textCursor();
    if(curCursor.isNull())
    {
        return false;
    }
    return curCursor.charFormat().fontItalic();
}

void DocumentController::setItalic(bool newItalic)
{
    QTextCharFormat textFormat;
    textFormat.setFontItalic(newItalic);
    setFormatting(textFormat);
    emit italicChanged();
}

bool DocumentController::underline() const
{
    QTextCursor curCursor = textCursor();
    if(curCursor.isNull())
    {
        return false;
    }
    return curCursor.charFormat().fontUnderline();
}

void DocumentController::setUnderline(bool newUnderline)
{
    QTextCharFormat textFormat;
    textFormat.setFontUnderline(newUnderline);
    setFormatting(textFormat);
    emit underlineChanged();
}

void DocumentController::executeUndoRedo(bool isUndo)
{
    m_qtextDocument = getQtextDocument();
    if(m_qtextDocument)
    {
        if(isUndo)
        {
            if(m_qtextDocument->isUndoAvailable())
            {
                m_qtextDocument->undo();

            }
        }
        else{
            if(m_qtextDocument->isRedoAvailable())
            {
                m_qtextDocument->redo();

            }
        }
        emit isUndoAvailableChanged();
        emit isRedoAvailableChanged();
    }
}

bool DocumentController::isUndoAvailable() const
{
    m_qtextDocument = getQtextDocument();
    if(m_qtextDocument)
    {
        return m_qtextDocument->isUndoAvailable();
    }
    return false;
}

bool DocumentController::isRedoAvailable() const
{
    m_qtextDocument = getQtextDocument();
    if(m_qtextDocument)
    {
        return m_qtextDocument->isRedoAvailable();
    }
    return false;
}

const QString DocumentController::curFileName() const
{
    const QString curFilePath = QQmlFile::urlToLocalFileOrQrc(m_currentFileUrl);
    QString curFileName = QFileInfo(curFilePath).fileName();
    if(curFileName.isEmpty())
    {
        curFileName = "untitled.txt";
    }
    return curFileName;
}

const Qt::Alignment DocumentController::textAlignment() const
{
    QTextCursor curCursor = textCursor();
    if(curCursor.isNull())
    {
        return Qt::AlignLeft;
    }
    return curCursor.blockFormat().alignment();
}

void DocumentController::setTextAlignment(const Qt::Alignment &newTextAlignment)
{
    QTextBlockFormat blockFormat;
    blockFormat.setAlignment(newTextAlignment);
    QTextCursor curCursor = textCursor();
    curCursor.mergeBlockFormat(blockFormat);
    emit textAlignmentChanged();
}

void DocumentController::printFile()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer);
    if(printDialog.exec() == QDialog::Accepted)
    {
        m_qtextDocument->print(&printer);
    }
}
