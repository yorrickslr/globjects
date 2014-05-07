#include "BindlessBufferImplementation.h"

#include <glbinding/functions.h>

#include <glow/Error.h>

namespace glow {

void * BindlessBufferImplementation::map(const Buffer * buffer, gl::GLenum access) const
{
    void * result = gl::MapNamedBufferEXT(buffer->id(), access);
    CheckGLError();

    return result;
}

void * BindlessBufferImplementation::mapRange(const Buffer * buffer, gl::GLintptr offset, gl::GLsizeiptr length, gl::GLbitfield access) const
{
    void* result = gl::MapNamedBufferRangeEXT(buffer->id(), offset, length, access);
    CheckGLError();

    return result;
}

bool BindlessBufferImplementation::unmap(const Buffer * buffer) const
{
    gl::GLboolean success = gl::UnmapNamedBufferEXT(buffer->id());
    CheckGLError();

    return success == gl::TRUE;
}

void BindlessBufferImplementation::setData(const Buffer * buffer, gl::GLsizeiptr size, const gl::GLvoid * data, gl::GLenum usage) const
{
    gl::NamedBufferDataEXT(buffer->id(), size, data, usage);
    CheckGLError();
}

void BindlessBufferImplementation::setSubData(const Buffer * buffer, gl::GLintptr offset, gl::GLsizeiptr size, const gl::GLvoid * data) const
{
    gl::NamedBufferSubDataEXT(buffer->id(), offset, size, data);
    CheckGLError();
}

void BindlessBufferImplementation::setStorage(const Buffer * buffer, gl::GLsizeiptr size, const gl::GLvoid * data, gl::GLbitfield flags) const
{
    gl::NamedBufferStorageEXT(buffer->id(), size, data, flags);
    CheckGLError();
}

void BindlessBufferImplementation::copySubData(const Buffer * buffer, Buffer * other, gl::GLintptr readOffset, gl::GLintptr writeOffset, gl::GLsizeiptr size) const
{
    gl::NamedCopyBufferSubDataEXT(buffer->id(), other->id(), readOffset, writeOffset, size);
    CheckGLError();
}

void BindlessBufferImplementation::getParameter(const Buffer * buffer, gl::GLenum pname, gl::GLint * data) const
{
    gl::GetNamedBufferParameterivEXT(buffer->id(), pname, data);
    CheckGLError();
}

void BindlessBufferImplementation::clearData(const Buffer * buffer, gl::GLenum internalformat, gl::GLenum format, gl::GLenum type, const void * data) const
{
    gl::ClearNamedBufferDataEXT(buffer->id(), internalformat, format, type, data);
    CheckGLError();
}

void BindlessBufferImplementation::clearSubData(const Buffer * buffer, gl::GLenum internalformat, gl::GLintptr offset, gl::GLsizeiptr size, gl::GLenum format, gl::GLenum type, const void * data) const
{
    gl::ClearNamedBufferSubDataEXT(buffer->id(), internalformat, offset, size, format, type, data);
    CheckGLError();
}

void BindlessBufferImplementation::flushMappedRange(const Buffer * buffer, gl::GLintptr offset, gl::GLsizeiptr length) const
{
    gl::FlushMappedNamedBufferRangeEXT(buffer->id(), offset, length);
    CheckGLError();
}

} // namespace glow
