#include "Grid.h"

Grid::Grid(int width, int columns, int margin) :
    columns(columns),
    margin(margin)
{
    itemSize = (width - (margin * (columns + 1))) / columns;
}

void Grid::next()
{
    col++;

    if (col >= columns)
    {
        col = 0;
        row++;
    }
}

QPointF Grid::pos()
{
    return QPointF(margin * (col + 1) + itemSize * col, margin * (row + 1) + itemSize * row);
}

int Grid::getItemSize()
{
    return itemSize;
}
