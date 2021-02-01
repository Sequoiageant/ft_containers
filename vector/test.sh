#!/bin/bash

RED='\033[0;31;1m' # Red bold
GREEN='\033[0;32;1m' # Green bold
YELLOW='\033[0;33;1m' # Yellow bold
NC='\033[0m' # No Color

clang++ -Wall -Wextra -Werror -std=c++98 -I../includes *.cpp && ./a.out > ft
clang++ -Wall -Wextra -Werror -std=c++98 -I../includes -D STD *.cpp && ./a.out > std

diff ft std

if [ $? -eq 0 ]
then
	echo "${GREEN}Perfect${NC}"
else
	echo "${RED}ERRORS${NC}"
fi

# rm ft
# rm std