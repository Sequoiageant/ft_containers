# !/bin/sh
clang++ -Wall -Wextra -Werror -std=c++98 main.cpp && ./a.out > ft
clang++ -Wall -Wextra -Werror -std=c++98 -D STD main.cpp && ./a.out > std
diff ft std