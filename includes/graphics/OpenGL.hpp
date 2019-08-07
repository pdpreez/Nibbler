/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenGL.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:23:26 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/07 15:30:08 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL_HPP
#define OPENGL_HPP

#include "KHR/khrplatform.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "IGlib.hpp"
#include "Shader.hpp"
#include <iostream>

class Shader;

class OpenGL: public IGlib
{
    public:
        OpenGL(unsigned int width, unsigned int height, unsigned int size);
        OpenGL(OpenGL const &rhs);
        OpenGL &operator=(OpenGL const &rhs);
        virtual ~OpenGL();
        
        virtual void startFrame();
        virtual void endFrame();
        virtual void drawSquare(unsigned int x, unsigned int y, struct s_color color);
        virtual void createWindow();
        virtual void closeWindow();
        virtual int retrieveInput();
    private:
        OpenGL();
        GLFWwindow *m_window;
        Shader *m_shader;
        unsigned int m_grid_width;
        unsigned int m_grid_height;
        unsigned int m_pixel_width;
        unsigned int m_pixel_height;
        static float m_vertices[];
        static unsigned int m_indices[];
        unsigned int m_vertexArray;
        unsigned int m_vertexBuffer;
        unsigned int m_elementBuffer;

        void initialise();
        static void error_callback(int error, const char *description);
};

extern "C"
{
    IGlib *create_renderer(unsigned int width, unsigned int height, unsigned int size);
}

#endif