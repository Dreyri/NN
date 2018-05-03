#pragma once

#include <optional>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "nn/2d/shader.hpp"

namespace nn {
class shader_program {
private:
  GLuint m_program_id;
  bool m_linked;

  /**
   * shaders which have not yet been linked, these will be detached and cleared
   * after linking
   */
  std::vector<GLuint> m_unlinked_shaders;

public:
  shader_program();
  ~shader_program();

  bool attach(const shader& s);
  bool link();
  bool is_linked() const;

  void bind() const;
  void unbind() const;

  void uniform(GLint location, const glm::mat4& m, bool transpose = false);
  void uniform(GLint location, GLint i);

  bool bind_attribute_location(const std::string& attr, GLint location) const;
  GLint uniform_location(const std::string& uniform) const;
  GLint attribute_location(const std::string& attr) const;

  std::optional<std::string> log() const;
};
} // namespace nn