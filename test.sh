
b=true
a=$([ "$b" == true ] && echo "-lm" || echo "")

echo "$a"