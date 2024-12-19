MAIN="main1.cpp menu_func.cpp menu_items.cpp"
APP=example

if [ ! -f $"APP" ]; then rm $"APP"
fi

g++ -std=c++11 $MAIN -o $APP

if [ $? -eq 0 ]; then
    ./"$APP"
else
    echo "Ошибка компиляции."
fi
