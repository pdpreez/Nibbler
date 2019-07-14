/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 08:18:10 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/14 14:51:46 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

#include "./glad/include/glad/glad.h"
#include "./glfw/include/GLFW/glfw3.h"

class Shader
{
    public:
        Shader(const char *vertexpath, const char *fragmentpath);
        Shader(Shader const &rhs);
        Shader &operator=(Shader const &rhs);
        ~Shader();
        
        unsigned int id;
        bool m_errors;
        void use() const;
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;

    private:
        Shader();
        void compileErrors(unsigned int shader, std::string type);
        
};