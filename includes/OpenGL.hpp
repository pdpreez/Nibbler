/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenGL.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:23:26 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/14 13:32:16 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL_HPP
#define OPENGL_HPP

#include "./glad/include/KHR/khrplatform.h"
#include "./glad/include/glad/glad.h"
#include "./glfw/include/GLFW/glfw3.h"
#include "IGlib.hpp"
#include <iostream>

class OpenGL: public IGlib
{
    public:
        OpenGL();
        OpenGL(unsigned int width, unsigned int height);
        OpenGL(OpenGL const &rhs);
        OpenGL &operator=(OpenGL const &rhs);
        ~OpenGL();
        virtual void refresh();
        virtual void drawEntity(IEntity const &entity);
        virtual void createWindow();
        virtual void closeWindow();
        virtual unsigned int retrieveInput();
    private:
        GLFWwindow *m_window;
        unsigned int m_screen_width;
        unsigned int m_screen_height;
        // unsigned int m_vertexArray;
        // unsigned int m_vertexBuffer;

        void initialise();
        static void error_callback(int error, const char *description);
};

#endif