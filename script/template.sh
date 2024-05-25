

PATH=$1
CLASSNAME=$2
UCLASSNAME=$(printf "%s" "$2" | /usr/bin/tr '[:lower:]' '[:upper:]')

/usr/bin/head -2 Classnnn.hpp | /usr/bin/sed "s/nnn/$UCLASSNAME/gi" > $PATH/headers/$CLASSNAME.hpp
echo >> $PATH/headers/$CLASSNAME.hpp 
/usr/bin/grep -A100 'class' Classnnn.hpp | /usr/bin/sed "s/nnn/$CLASSNAME/gi" >> $PATH/headers/$CLASSNAME.hpp
/bin/cat Classnnn.cpp | /usr/bin/sed "s/nnn/$CLASSNAME/gi" > $PATH/sources/$CLASSNAME.cpp
