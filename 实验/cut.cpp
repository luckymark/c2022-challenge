#include "play.h"

bool cut(int x,int y,Node *node) {
    inputToMap(node);
    if (x >= 1&&x <= 15&&y >= 1&&y <= 15&&subMap[x][y] == 0){
        for (int i = -2;i <= 2; ++i) {
            for (int j = -2;j <= 2; ++j) {
                if (subMap[x+i][y+j] != 0) return true;
            }
        }
    }
    return false;
}
