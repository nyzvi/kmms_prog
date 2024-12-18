MAIN="main.cpp menu_func.cpp menu_items.cpp"
APP=example

if [ ! -f $APP ]; then rm $APP
fi

g++ -std=c++11 $MAIN -o $APP

./$APP