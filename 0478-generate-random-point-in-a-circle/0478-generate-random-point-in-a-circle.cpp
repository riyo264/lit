class Solution {
public:
    double radius, x_center, y_center;
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        std::random_device rd; 
        std::mt19937 gen(rd());
        uniform_real_distribution<double> dist;
        double theta = 2 * M_PI * dist(gen);
        double r = radius * sqrt(dist(gen));

        double x = x_center + r * cos(theta);
        double y = y_center + r * sin(theta);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */