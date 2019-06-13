INCLUDE=/home/hz/download/jsoncpp-src-0.5.0/include
LIB_PATH=/home/hz/download/jsoncpp-src-0.5.0/libs

src=json2.cpp
src2=test.cpp

json:$(src2)
	g++ -o $@ $^ -I$(INCLUDE) -L$(LIB_PATH) -ljsoncpp
	export LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(LIB_PATH)

.PHONY:clean
clean:
	rm -rf json
#	unset LD_LIBRARY_PATH (不需要删除，因为子shell的环境变量对父shell无影响)

# Linux下设置和删除环境变量的方法：
#  bash下   export 变量名=值
#           unset 变量名
#  csh下
#           #include <stdlib.h>
#           int setenv(const char *name, const char *value, int overwrite);
#	        int unsetenv(const char *name);
