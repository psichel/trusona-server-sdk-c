# MIT License
#
# Copyright (c) 2016, 2017 Trusona Inc (www.trusona.com) All Rights Reserved
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

all: objects
	cc -L /usr/local/lib -shared json.o net.o trusona.o utils.o hmac.o base64.o \
		-luuid -lcurl -ljansson -lcrypto -o trusona.so

objects: clean
	cc -Wall -fPIC -c trusona.c -o trusona.o
	cc -Wall -fPIC -c base64.c  -o base64.o
	cc -Wall -fPIC -c utils.c   -o utils.o
	cc -Wall -fPIC -c json.c    -o json.o
	cc -Wall -fPIC -c hmac.c    -o hmac.o
	cc -Wall -fPIC -c net.c     -o net.o

clean:
	find . -name "*.o" -o -name "*.so" -o -name "a.out" | xargs rm -f
	rm -rf infer-out

install: all
	$(shell mkdir -p /usr/local/lib)
	$(shell strip trusona.so 2>/dev/null)
	$(shell cp trusona.so /usr/local/lib)
	$(shell rm -rf *.o infer-out)

test:
	## infer is available here - http://fbinfer.com
	infer -- make all