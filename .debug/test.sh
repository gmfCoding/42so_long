while true ; do
./program &
last_pid=$!
sleep 1
kill -KILL $last_pid
done
