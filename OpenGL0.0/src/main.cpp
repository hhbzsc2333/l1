#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "LSystem.h"
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

// Function to handle window resize
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void HelpMarker(const char* desc) {
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered()) {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}


void display(GLFWwindow* window) {
    // ImGui frame start
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Create ImGui window
    ImGui::Begin("Controls");
    ImGui::Text("parameters:");
    static int iteration = 0;
    static float angle = 0.0f;
    static float lineLength = 0.0f;
    ImGui::InputInt("Iterations", &iteration);
    ImGui::InputFloat("Angle", &angle);
    ImGui::InputFloat("Line Length", &lineLength);
    static float color[3] = { 0.0f, 1.0f, 0.0f };

    static char initialp[128] = "initialp";
    static char rule1[128] = "(rule1)->";
    static char rule2[128] = "(rule2)->";

    ImGui::InputText("Initialp", initialp, IM_ARRAYSIZE(initialp));

    ImGui::InputText("Rule 1", rule1, IM_ARRAYSIZE(rule1));
    ImGui::SameLine(); HelpMarker("The iteration function here must use '->'");

    ImGui::InputText("Rule 2", rule2, IM_ARRAYSIZE(rule2));
    ImGui::SameLine(); HelpMarker("The iteration function here must use '->'");

    ImGui::ColorEdit3("Line Color", color);


    
    ImGui::End();

   /* std::string initialp = "F";
    std::string rule1 = "F->F[+F]F[-F]F";
    std::string rule2 = "F->F[+F]F[-F]F";*/
    std::string result = combineLine(iteration, initialp, rule1, rule2);
    auto points = getStack(result, angle, lineLength);




    // Clear the buffer with white color
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);

    drawLSystem(points, lineLength,color);

    // Render ImGui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main(void) {
    GLFWwindow* window;

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    window = glfwCreateWindow(640, 480, "OpenGL L-System Drawing", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window\n";
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Set the callback for window resize


    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return -1;
    }

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    // Setup ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    while (!glfwWindowShouldClose(window)) {
        display(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}

