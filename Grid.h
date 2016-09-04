#ifndef GRID_H
#define GRID_H

#include <QPointF>

class Grid
{
    public:

        Grid(int width, int columns, int margin = 0);

        void next();
        QPointF pos();
        int getItemSize();

    private:

        int itemSize;
        int columns;
        int margin;

        int col = 0;
        int row = 0;
};

#endif // GRID_H
