while true ; do
./so_long &
last_pid=$!
sleep 1
kill -KILL $last_pid
done
