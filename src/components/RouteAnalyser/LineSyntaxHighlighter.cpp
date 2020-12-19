/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of Pingnoo
 *
 * Created by Adrian Carpenter on 17/12/2020.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "LineSyntaxHighlighter.h"

Nedrysoft::RouteAnalyser::LineSyntaxHighlighter::LineSyntaxHighlighter(QTextDocument *parent, SyntaxFunction function) :
        QSyntaxHighlighter(parent),
        m_syntaxFunction(function) {

}

void Nedrysoft::RouteAnalyser::LineSyntaxHighlighter::updateSyntax() {
    if (document()==nullptr) {
        return;
    }

    for (auto currentBlock=1;currentBlock<=document()->blockCount();currentBlock++) {
        this->rehighlightBlock(this->document()->findBlockByLineNumber(currentBlock));
    }
}

void Nedrysoft::RouteAnalyser::LineSyntaxHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat textFormat;

    if (!m_syntaxFunction(text)) {
        textFormat.setUnderlineColor(Qt::yellow);
        textFormat.setForeground(Qt::yellow);
        textFormat.setUnderlineStyle(QTextCharFormat::WaveUnderline);
        textFormat.setFontItalic(true);
    }

    setFormat(0, text.length(), textFormat);
}