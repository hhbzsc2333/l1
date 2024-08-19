/*#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stack>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <cmath>
#include <string>




class Point {
public:
    float x, y, angle;

    Point() : x(0), y(0), angle(90) {}

    void setStartX(float startX) {
        x = startX;
    }

    void setStartY(float startY) {
        y = startY;
    }

    void setAngle(float ang) {
        angle = ang;
    }

    float getStartX() const {
        return x;
    }

    float getStartY() const {
        return y;
    }

    float getAngle() const {
        return angle;
    }
};*/

/*std::string combineLine(int iteration, std::string axioms, std::string rule1, std::string rule2) {
    std::string products;
    std::string product = axioms;
    for (int n = 0; n < iteration; n++) {
        products = "";
        for (size_t i = 0; i < product.length(); i++) {
            char current = product[i];
            if (current == rule1[0]) {
                products += rule1.substr(2);
            }
            else if (current == rule2[0]) {
                products += rule2.substr(2);
            }
            else {
                products += current;
            }
        }
        product = products;
    }
    return products;
}

std::stack<Point> getStack(const std::string& products, float angle, float lineLength) {

    std::stack<Point> st;
    std::stack<Point> saveStack;
    Point currentPoint;  // 用来跟踪当前的位置和角度
    /*currentPoint.setStartX(0.0);
    currentPoint.setStartY(0.0);
    currentPoint.setAngle(90.0);  // 初始角度为90度

    for (size_t i = 0; i < products.length(); i++) {
        char letter = products[i];
        switch (letter) {
        case 'F': {
            float newX = currentPoint.getStartX() + lineLength * cos(currentPoint.getAngle() * M_PI / 180.0);
            float newY = currentPoint.getStartY() + lineLength * sin(currentPoint.getAngle() * M_PI / 180.0);

            Point newPoint;
            newPoint.setStartX(newX);
            newPoint.setStartY(newY);
            newPoint.setAngle(currentPoint.getAngle());

            st.push(currentPoint);
            currentPoint = newPoint;
            break;
        }
        case 'f': {
            float newX = currentPoint.getStartX() + lineLength * cos(currentPoint.getAngle() * M_PI / 180.0);
            float newY = currentPoint.getStartY() + lineLength * sin(currentPoint.getAngle() * M_PI / 180.0);

            currentPoint.setStartX(newX);
            currentPoint.setStartY(newY);
            break;

        }
        case '+':
            currentPoint.setAngle(currentPoint.getAngle() - angle);  // 向右转
            break;
        case '-':
            currentPoint.setAngle(currentPoint.getAngle() + angle);  // 向左转
            break;
        case '[':
            saveStack.push(currentPoint);  // 保存当前点
            break;
        case ']':
            if (!saveStack.empty()) {
                currentPoint = saveStack.top();  // 恢复保存的点
                saveStack.pop();
            }
            break;
        }
    }
    st.push(currentPoint);  // 将最后的点也推入栈
    return st;
}

void drawLSystem(const std::stack<Point>& points, float lineLength) {
    std::stack<Point> localPoints = points; // Make a copy because we can't modify the original stack
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0); // Set draw color to green

    glBegin(GL_LINES);
    Point previousPoint = localPoints.top(); // 起始点
    localPoints.pop();

    while (!localPoints.empty()) {
        Point p = localPoints.top();
        localPoints.pop();

        glVertex2f(previousPoint.getStartX(), previousPoint.getStartY());
        glVertex2f(p.getStartX(), p.getStartY());

        previousPoint = p;  // 更新上一点
    }
    glEnd();
   
}

void display(GLFWwindow* window) {
    std::string axioms = "f";
    std::string rule1 = "F->FF";
    std::string rule2 = "f->F[-f]+f";
    std::string result = combineLine(10, axioms, rule1, rule2);
    auto points = getStack(result, 45.0f,0.001f);

    //清理颜色缓冲区，设置背景为白色
   // glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    //glClear(GL_COLOR_BUFFER_BIT);

    drawLSystem(points, 0.1f);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
   /* if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    /*window = glfwCreateWindow(640, 480, "OpenGL L-System Drawing", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window\n";
        return -1;
    }

    /* Make the window's context current */
    /*glfwMakeContextCurrent(window);

    /* Initialize GLEW */
    /*if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return -1;
    }

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    /* Loop until the user closes the window */
    /* while (!glfwWindowShouldClose(window)) {
        display(window);
    }

    glfwTerminate();
    return 0;
}*/
