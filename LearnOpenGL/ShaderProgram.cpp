//#include "Common.h"
//#include "shader_s.h"
//
//float vertices[] = {
// 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
//-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
// 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
//};
//
//
//float CircleY(float x) {
//
//	return cos(x) - 0.5f;
//}
//
//
//int main() {
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to init GLAD" << std::endl;
//		return -1;
//	}
//
//	Shader ourShader("D:\\VsStudy\\LearnOpenGL\\Shaders\\ShaderLes\\vertex.shader", "D:\\VsStudy\\LearnOpenGL\\Shaders\\ShaderLes\\frag.shader");
//	
//	unsigned int VBO;
//	unsigned int VAO;
//	unsigned int EBO;
//
//	//生成缓冲
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//
//	//绑定缓冲
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//
//
//
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window)) {
//
//		
//		processInput(window);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//		//绘制
//
//		float rPosX = sin(glfwGetTime());
//		float rPosY = CircleY(rPosX);
//		ourShader.use();
//		ourShader.setFloat("rPosX", rPosX);
//		ourShader.setFloat("rPosY", rPosY);
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(0);
//
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//
//
//	glfwTerminate();
//	return 0;
//
//}
//
//
