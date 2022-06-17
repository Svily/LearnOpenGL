//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#include "Common.h"
//#include "shader_s.h"
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//float vertices[] = {
//	//     ---- λ�� ----         - �������� -
// 0.5f,  0.5f, 0.0f,      1.0f, 1.0f,   // ����
// 0.5f, -0.5f, 0.0f,      1.0f, 0.0f,   // ����
//-0.5f, -0.5f, 0.0f,      0.0f, 0.0f,   // ����
// -0.5f,  0.5f, 0.0f,     0.0f, 1.0f   // ����
//};
//
//unsigned int indices[] = {
//	// ע��������0��ʼ! 
//	// ����������(0,1,2,3)���Ƕ�������vertices���±꣬
//	// �����������±��������ϳɾ���
//
//	0, 1, 3, // ��һ��������
//	1, 2, 3  // �ڶ���������
//};
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
//	Shader ourShader("D:\\VsStudy\\LearnOpenGL\\Shaders\\Transform\\vertex.shader", "D:\\VsStudy\\LearnOpenGL\\Shaders\\Transform\\frag.shader");
//
//	unsigned int VBO;
//	unsigned int VAO;
//	unsigned int EBO;
//
//	//���ɻ���
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//
//	//�󶨻���
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//
//
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	// Ϊ��ǰ�󶨵�����������û��ơ����˷�ʽ
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	// ���ز���������
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load("D:\\VsStudy\\LearnOpenGL\\Images\\sea.png", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//
//
//	stbi_image_free(data);
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//
//	float Alpha = 1;
//	ourShader.setFloat("rAlpha", Alpha);
//	while (!glfwWindowShouldClose(window)) {
//
//
//		processInput(window);
//
//		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
//
//			Alpha += 0.01f;
//			if (Alpha >= 1.0f)
//				Alpha = 1.0f;
//			std::cout << "Press UP" << Alpha << std::endl;
//		}
//
//		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
//
//			Alpha -= 0.01f;
//			if (Alpha <= 0.0f)
//				Alpha = 0.0f;
//			std::cout << "Press Down " << Alpha << std::endl;
//		}
//
//		int mixValue = glGetUniformLocation(ourShader.ID, "rAlpha");
//		glUniform1f(mixValue, Alpha);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//		//����
//		ourShader.use();
//		glBindVertexArray(VAO);
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glm::mat4 trans;
//
//
//		trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));
//		trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
//		unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
//		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
//
//
//		glBindTexture(GL_TEXTURE_2D, texture);
//
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//
//	glfwTerminate();
//	return 0;
//
//}
//
//
