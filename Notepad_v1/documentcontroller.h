#ifndef DOCUMENTCONTROLLER_H
#define DOCUMENTCONTROLLER_H

#include <QObject>
#include <QQuickTextDocument>
#include <QTextDocument>
#include <QTextCursor>
#include <QPrintDialog>
#include <QPrinter>

class DocumentController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQuickTextDocument* notepadDoc READ notepadDoc WRITE SetnotepadDoc NOTIFY notepadDocChanged)
    Q_PROPERTY(int cursorPosition READ cursorPosition WRITE setCursorPosition NOTIFY cursorPositionChanged)
    Q_PROPERTY(int selectionStart READ selectionStart WRITE setSelectionStart NOTIFY selectionStartChanged)
    Q_PROPERTY(int selectionEnd READ selectionEnd WRITE setSelectionEnd NOTIFY selectionEndChanged)
    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(int fontSize READ fontSize WRITE setFontSize NOTIFY fontSizeChanged)
    Q_PROPERTY(QString fontFamily READ fontFamily WRITE setFontFamily NOTIFY fontFamilyChanged)
    Q_PROPERTY(bool bold READ bold WRITE setBold NOTIFY boldChanged)
    Q_PROPERTY(bool italic READ italic WRITE setItalic NOTIFY italicChanged)
    Q_PROPERTY(bool underline READ underline WRITE setUnderline NOTIFY underlineChanged)
    Q_PROPERTY(Qt::Alignment textAlignment READ textAlignment WRITE setTextAlignment NOTIFY textAlignmentChanged)
    Q_PROPERTY(bool isUndoAvailable READ isUndoAvailable NOTIFY isUndoAvailableChanged)
    Q_PROPERTY(bool isRedoAvailable READ isRedoAvailable NOTIFY isRedoAvailableChanged)
    Q_PROPERTY(QString curFileName READ curFileName NOTIFY curFileNameChanged)

public:
    explicit DocumentController(QObject *parent = nullptr);

    QQuickTextDocument *notepadDoc() const;
    void SetnotepadDoc(QQuickTextDocument *newNotepadDoc);

    int cursorPosition() const;
    void setCursorPosition(int newCursorPosition);

    int selectionStart() const;
    void setSelectionStart(int newSelectionStart);

    int selectionEnd() const;
    void setSelectionEnd(int newSelectionEnd);

    const QColor &textColor() const;
    void setTextColor(const QColor &newTextColor);

    int fontSize() const;
    void setFontSize(int newFontSize);

    const QString fontFamily() const;
    void setFontFamily(const QString &newFontFamily);

    bool bold() const;
    void setBold(bool newBold);

    bool italic() const;
    void setItalic(bool newItalic);

    bool underline() const;
    void setUnderline(bool newUnderline);
    Q_INVOKABLE void executeUndoRedo(bool isUndo);

    bool isUndoAvailable() const;

    bool isRedoAvailable() const;

    const QString curFileName() const;

    const Qt::Alignment textAlignment() const;
    void setTextAlignment(const Qt::Alignment &newTextAlignment);



signals:
    void notepadDocChanged();
    void fileContentLoaded(const QString &content, int format);
    void cursorPositionChanged();

    void selectionStartChanged();

    void selectionEndChanged();

    void textColorChanged();

    void fontSizeChanged();

    void fontFamilyChanged();

    void boldChanged();

    void italicChanged();

    void underlineChanged();

    void isUndoAvailableChanged();

    void isRedoAvailableChanged();

    void curFileNameChanged();

    void textAlignmentChanged();

public slots:
    void openFile(const QUrl &fileUrl);
    bool saveContent();
    bool saveAs(const QUrl &fileUrl);
    void createFile(const QUrl &fileUrl);
    void printFile();

private:
    QTextDocument *qtextDocument() const;
    void setFormatting(const QTextCharFormat &textFormat);
    void setQtextDocument(QTextDocument *newQtextDocument);
    void resetFormatting();
    QTextCursor textCursor() const;
    int m_cursorPosition;
    int m_selectionStart;
    int m_selectionEnd;

    QUrl m_currentFileUrl;
    static QTextDocument *m_qtextDocument;
    QQuickTextDocument *m_notepadDoc;
    QColor m_textColor;
    int m_fontSize;
    QString m_fontFamily;
    bool m_bold;
    bool m_italic;
    bool m_underline;
    bool m_isUndoAvailable;
    bool m_isRedoAvailable;

    QTextDocument* getQtextDocument() const;
    QString m_curFileName;
    Qt::Alignment m_textAlignment;
};

#endif // DOCUMENTCONTROLLER_H
