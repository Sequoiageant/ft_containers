#!/bin/bash

RED='\033[0;31;1m' # Red bold
GREEN='\033[0;32;1m' # Green bold
YELLOW='\033[0;33;1m' # Yellow bold
NC='\033[0m' # No Color


######################### CONFIGURATION #########################

# List of the srcs paths, comment the ones you don't want to run
srcs=(		\
	list	\
	vector	\
	stack	\
	queue	\
	# map		\
	)

flags='-Wall -Wextra -Werror -std=c++98'

includes='-I./includes'

test_dir='TESTS'

####################### END CONFIGURATION #######################
# Do not edit from here


# Find container name in src array
find_value () {
	for i in "${srcs[@]}"
	do
		if [ "$i" == "$1" ] ; then
			return 0;
		fi
	done
	return 1;

}

# clean all out files
clean () {
	rm -rf ./$test_dir
}

# Compile and run diff tests
test_container () {

	# Compile ft sources
	clang++ $flags $includes ./$1/*.cpp -o ./$test_dir/ft_$1.out && ./$test_dir/ft_$1.out > ./$test_dir/ft_$1 2> /dev/null
	clang++ $flags $includes -D STD ./$1/*.cpp -o ./$test_dir/std_$1.out && ./$test_dir/std_$1.out > ./$test_dir/std_$1 2> /dev/null
	
	# Make diff between ft and std container
	diff ./$test_dir/ft_$1 ./$test_dir/std_$1 > ./$test_dir/$1.diff

	# Print result
	if [ $? -eq 0 ]
	then
		echo -e "$1: ${GREEN}Perfect${NC}"
	else
		echo -e "$1: ${RED}ERRORS${NC} ==> Saved in ./$test_dir/$1.diff"
			# cat $1.diff
		fi
	}

# If first argument is "Name_of_a_container" in lowercase, excute test only on this container
if [ $# -ge 1 ]
then
	if [ $1 != 'clean' ]
	then
		find_value $1;
		if [ $? == 0 ]
		then
			mkdir -p ./$test_dir
			test_container $1;
		else
			echo "Container \"$1\" NOT FOUND"
		fi

	else
		clean;
	fi
else
	mkdir -p ./$test_dir
	for src in "${srcs[@]}"
	do
		test_container $src;
	done
fi
