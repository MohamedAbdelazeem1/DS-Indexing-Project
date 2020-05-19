#ifndef DOCVIEWER_H
#define DOCVIEWER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class docViewer : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    docViewer(QTextDocument *parent = 0);
    void addRule(std::string word);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    HighlightingRule rule;
    QTextCharFormat searchedWord;
};
#endif // DOCVIEWER_H
