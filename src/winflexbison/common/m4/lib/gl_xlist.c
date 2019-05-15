/* Abstract sequential list data type, with out-of-memory checking.
   Copyright (C) 2009-2011 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2009.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <config.h>

/* Specification.  */
#include "gl_xlist.h"

#if !HAVE_INLINE

gl_list_t
gl_list_create_empty (gl_list_implementation_t implementation,
                      gl_listelement_equals_fn equals_fn,
                      gl_listelement_hashcode_fn hashcode_fn,
                      gl_listelement_dispose_fn dispose_fn,
                      bool allow_duplicates)
{
  gl_list_t result =
    gl_list_nx_create_empty (implementation, equals_fn, hashcode_fn, dispose_fn,
                             allow_duplicates);
  if (result == NULL)
    xalloc_die ();
  return result;
}

gl_list_t
gl_list_create (gl_list_implementation_t implementation,
                gl_listelement_equals_fn equals_fn,
                gl_listelement_hashcode_fn hashcode_fn,
                gl_listelement_dispose_fn dispose_fn,
                bool allow_duplicates,
                size_t count, const void **contents)
{
  gl_list_t result =
    gl_list_nx_create (implementation, equals_fn, hashcode_fn, dispose_fn,
                       allow_duplicates, count, contents);
  if (result == NULL)
    xalloc_die ();
  return result;
}

void
gl_list_node_set_value (gl_list_t list, gl_list_node_t node, const void *elt)
{
  int result = gl_list_node_nx_set_value (list, node, elt);
  if (result < 0)
    xalloc_die ();
}

gl_list_node_t
gl_list_set_at (gl_list_t list, size_t position, const void *elt)
{
  gl_list_node_t result = gl_list_nx_set_at (list, position, elt);
  if (result == NULL)
    xalloc_die ();
  return result;
}

gl_list_node_t
gl_list_add_first (gl_list_t list, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_first (list, elt);
  if (result == NULL)
    xalloc_die ();
  return result;
}

gl_list_node_t
gl_list_add_last (gl_list_t list, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_last (list, elt);
  if (result == NULL)
    xalloc_die ();
  return result;
}

gl_list_node_t
gl_list_add_before (gl_list_t list, gl_list_node_t node, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_before (list, node, elt);
  if (result == NULL)
    xalloc_die ();
  return result;
}

gl_list_node_t
gl_list_add_after (gl_list_t list, gl_list_node_t node, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_after (list, node, elt);
  if (result == NULL)
    xalloc_die ();
  return result;
}

gl_list_node_t
gl_list_add_at (gl_list_t list, size_t position, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_at (list, position, elt);
  if (result == NULL)
    xalloc_die ();
  return result;
}

gl_list_node_t
gl_sortedlist_add (gl_list_t list, gl_listelement_compar_fn compar,
                   const void *elt)
{
  gl_list_node_t result = gl_sortedlist_nx_add (list, compar, elt);
  if (result == NULL)
    xalloc_die ();
  return result;
}

#endif
