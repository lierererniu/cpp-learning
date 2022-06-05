class Solution {
public:
    double r, r2, x, y;
    Solution(double radius, double x_center, double y_center): r(radius), x(x_center), y(y_center) {
        r2 = radius * radius;
    }
    // 正方形内随机采样
    vector<double> randPoint() {
        while (1) {
            // [-1, 1]
            double rx = rand() / double(RAND_MAX) * 2 * r - r + x;
            double ry = rand() / double(RAND_MAX) * 2 * r - r + y;
            //判断是否在圆内
            if (((x - rx) * (x - rx) + (y - ry) * (y - ry)) <= r2) 
                return vector<double> {rx, ry};
        }
    }
};
