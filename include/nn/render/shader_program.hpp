#pragma once

#include <optional>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "nn/render/shader.hpp"

namespace nn {
class shader_program {
public:
  static constexpr int POSITION_LOCATION = 0;
  static constexpr int TEXCOORD_LOCATION = 2;
  static constexpr int SAMPLER_LOCATION = 8;
  static constexpr int MVP_LOCATION = 3;

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
  shader_program(const shader_program&) = delete;
  shader_program(shader_program&& other);
  ~shader_program();

  shader_program& operator=(const shader_program&) = delete;
  shader_program& operator=(shader_program&& other);

  bool attach(const shader& s);
  bool link();
  bool is_linked() const;
  bool valid() const;

  void bind() const;
  void unbind() const;

  void uniform(GLint location, const glm::mat4& m,
               bool transpose = false) const;
  void uniform(GLint location, GLint i) const;

  bool bind_attribute_location(const std::string& attr, GLint location) const;
  GLint uniform_location(const std::string& uniform) const;
  GLint attribute_location(const std::string& attr) const;

  std::optional<std::string> log() const;
};
} // namespace nn