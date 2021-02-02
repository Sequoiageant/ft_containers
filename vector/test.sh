#!/bin/bash

RED='\033[0;31;1m' # Red bold
GREEN='\033[0;32;1m' # Green bold
YELLOW='\033[0;33;1m' # Yellow bold
NC='\033[0m' # No Color

clang++ -Wall -Wextra -Werror -std=c++98 -I../includes *.cpp && ./a.out > ft 2> /dev/null
clang++ -Wall -Wextra -Werror -std=c++98 -I../includes -D STD *.cpp && ./a.out > std 2> /dev/null

diff ft std

if [ $? -eq 0 ]
then
	echo -e "${GREEN}Perfect${NC}"
else
	echo -e "${RED}ERRORS${NC}"
fi

if [ $# -ge 1 ] && [ $1 = 'clean' ]
then
	rm ft std
fi
