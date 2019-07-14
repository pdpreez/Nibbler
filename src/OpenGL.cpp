/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenGL.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:59:07 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/14 13:33:32 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenGL.hpp"

OpenGL::OpenGL()
:m_screen_width(800), m_screen_height(600)
{
    initialise();
}

OpenGL::OpenGL(unsigned int width, unsigned int height)
:m_screen_width(width), m_screen_height(height)
{
    initialise();
}

OpenGL::OpenGL(OpenGL const &rhs)
{
    *this = rhs;
}

OpenGL &OpenGL::operator=(OpenGL const &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

OpenGL::~OpenGL()
{
    glfwTerminate();
}

// Private methods

void OpenGL::initialise()
{
    if (!glfwInit())
        throw std::exception();
        
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwSetErrorCallback(error_callback);
    
}

void OpenGL::error_callback(int error, const char *description)
{
    std::cout << "OpenGL error: " << error << std::endl;
    std::cout << "OpenGL error: " << description << std::endl;
}

// Public methods

void OpenGL::createWindow()
{
    int height, width;
    
    m_window = glfwCreateWindow(m_screen_width, m_screen_height, "Nibbler", nullptr, nullptr);
    if (!m_window)
        throw std::exception();
    glfwMakeContextCurrent(m_window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwGetFramebufferSize(m_window, &width, &height);
    glViewport(0, 0, width, height);
}

void OpenGL::closeWindow()
{
    glfwTerminate();
}

unsigned int OpenGL::retrieveInput()
{
    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        return 0;
    else
        return 1;
}

void OpenGL::refresh()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void OpenGL::drawEntity(IEntity const &entity)
{
    (void)entity;
}