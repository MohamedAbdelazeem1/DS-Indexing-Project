#include "docviewer.h"

docViewer::docViewer(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{

    searchedWord.setForeground(Qt::red);
    searchedWord.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("");
    rule.format=searchedWord;

}

void docViewer::addRule(std::string word){
    rule.pattern = QRegularExpression(QString::fromStdString(word));
}

void docViewer::highlightBlock(const QString &text)
{
    QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), rule.format);
    }
    setCurrentBlockState(0);
}
