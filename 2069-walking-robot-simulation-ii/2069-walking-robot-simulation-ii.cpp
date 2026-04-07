class Robot {
public:
    int x = 0;
    int y = 0;
    int dir = 2;
    int height;
    int width;
    int perimeter;
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        vector<vector<int>> grid(height, vector<int>(width));
        perimeter = 2 * (width + height - 2);
    }
    
    void step(int num) {
        num %= perimeter;
        if(num == 0 && x == 0 && y == 0) dir = -1;
        while(num > 0) {
            if(dir == 2) {
                if(x + 1 < width) x++;
                else { dir = 1; y++; }
            }
            else if(dir == 1) {
                if(y + 1 < height) y++;
                else { dir = -2; x--; }
            }
            else if(dir == -2) {
                if(x - 1 >= 0) x--;
                else { dir = -1; y--; }
            }
            else {
                if(y - 1 >= 0) y--;
                else { dir = 2; x++; }
            }
            num--;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if(dir == 1) {
            return "North";
        }
        else if(dir == -1) {
            return "South";
        }
        else if(dir == 2) {
            return "East";
        }
        return "West";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */