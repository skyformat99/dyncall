#!/usr/bin/python
#//////////////////////////////////////////////////////////////////////////////
#
# Copyright (c) 2007,2008 Daniel Adler <dadler@uni-goettingen.de>, 
#                         Tassilo Philipp <tphilipp@potion-studios.com>
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#
#//////////////////////////////////////////////////////////////////////////////


import random
import sys

N = 100
MINARG = 0
MAXARG = 19

argtypes = [ 'B','c','s','i','l','L','f','d','p' ]
apitypes = [ '_' ]

def sig(n):
  s = ""
  x = random.randint( 0, len(apitypes)-1 )
  # s += apitypes[x]
  for i in xrange(0,n):
    x = random.randint( 0, len(argtypes)-1 )
    s += argtypes[x]
  return s

for i in xrange(0,N):
  n = random.randint(MINARG,MAXARG)
  sys.stdout.write( sig(n) )
  sys.stdout.write( "\n" )
