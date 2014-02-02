/* NOTE: Do not edit this file, it is generated by a script:
   Export.py --api gl 4.4 --api wgl 4.4 --api glx 4.4 --api cgl 1.4 --api egl 1.0 --outdir .
*/

/*
  Copyright (c) 2011-2013 NVIDIA Corporation
  Copyright (c) 2011-2013 Cass Everitt
  Copyright (c) 2012-2013 Scott Nations
  Copyright (c) 2012 Mathias Schott
  Copyright (c) 2012-2013 Nigel Stewart
  Copyright (c) 2012-2013 Google Inc.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
  Intended formatting conventions:
  $ astyle --style=allman --indent=spaces=2 --indent-switches
*/

#include "RegalUtil.h"

REGAL_GLOBAL_BEGIN

#include "RegalPrivate.h"
#include "RegalContext.h"
#include "RegalDispatch.h"
#include "Quads.h"
#include "QuadsProcs.h"

extern "C" Regal::Layer * createQuads( Regal::RegalContext * ctx ) {
  return new Regal::Emu::Quads( ctx );
}

REGAL_GLOBAL_END

REGAL_NAMESPACE_BEGIN

using namespace Emu;

static void REGAL_CALL quads_glBindBuffer(Layer *_layer, GLenum target, GLuint buffer)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // prefix
  self->glBindBuffer( target, buffer );

  RglBindBuffer( orig, target, buffer );

}

static void REGAL_CALL quads_glCullFace(Layer *_layer, GLenum mode)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // prefix
  self->glCullFace( mode );

  RglCullFace( orig, mode );

}

static void REGAL_CALL quads_glDisable(Layer *_layer, GLenum cap)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // prefix
  self->glDisable( cap );

  RglDisable( orig, cap );

}

static void REGAL_CALL quads_glDrawArrays(Layer *_layer, GLenum mode, GLint first, GLsizei count)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // impl

  if ( self->glDrawArrays( mode, first, count ) ) {
    return;
  }

  RglDrawArrays( orig, mode, first, count );

}

static void REGAL_CALL quads_glDrawArraysEXT(Layer *_layer, GLenum mode, GLint first, GLsizei count)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // impl

  if ( self->glDrawArrays( mode, first, count ) ) {
    return;
  }

  RglDrawArraysEXT( orig, mode, first, count );

}

static void REGAL_CALL quads_glEnable(Layer *_layer, GLenum cap)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // prefix
  self->glEnable( cap );

  RglEnable( orig, cap );

}

static void REGAL_CALL quads_glFrontFace(Layer *_layer, GLenum mode)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // prefix
  self->glFrontFace( mode );

  RglFrontFace( orig, mode );

}

static void REGAL_CALL quads_glPolygonMode(Layer *_layer, GLenum face, GLenum mode)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // prefix
  self->glPolygonMode( face, mode );

  RglPolygonMode( orig, face, mode );

}

static void REGAL_CALL quads_glProvokingVertex(Layer *_layer, GLenum mode)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // prefix
  self->glProvokingVertex( mode );

  RglProvokingVertex( orig, mode );

}

static void REGAL_CALL quads_glProvokingVertexEXT(Layer *_layer, GLenum mode)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // prefix
  self->glProvokingVertex( mode );

  RglProvokingVertexEXT( orig, mode );

}

static void REGAL_CALL quads_glShadeModel(Layer *_layer, GLenum mode)
{
  Quads * self = static_cast<Quads *>(_layer);

  QuadsOriginate & orig = self->orig;

  // prefix
  self->glShadeModel( mode );

  RglShadeModel( orig, mode );

}

void QuadsIntercept( Layer *layer, Dispatch::GL & dt ) {
  dt.glBindBuffer         = MakeRegalProc(quads_glBindBuffer, layer);
  dt.glCullFace           = MakeRegalProc(quads_glCullFace, layer);
  dt.glDisable            = MakeRegalProc(quads_glDisable, layer);
  dt.glDrawArrays         = MakeRegalProc(quads_glDrawArrays, layer);
  dt.glDrawArraysEXT      = MakeRegalProc(quads_glDrawArraysEXT, layer);
  dt.glEnable             = MakeRegalProc(quads_glEnable, layer);
  dt.glFrontFace          = MakeRegalProc(quads_glFrontFace, layer);
  dt.glPolygonMode        = MakeRegalProc(quads_glPolygonMode, layer);
  dt.glProvokingVertex    = MakeRegalProc(quads_glProvokingVertex, layer);
  dt.glProvokingVertexEXT = MakeRegalProc(quads_glProvokingVertexEXT, layer);
  dt.glShadeModel         = MakeRegalProc(quads_glShadeModel, layer);
}

REGAL_NAMESPACE_END