find . -name '*.sh' | grep -o '[^/]*$' | cut -d '.' -f1
