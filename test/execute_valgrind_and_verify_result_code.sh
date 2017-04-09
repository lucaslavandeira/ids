#! /bin/sh

valgrindErrorCode=42
valgrindExec=/usr/bin/valgrind
valgrindOut=../test/valgrind.out
supressions=../test/suppressions.txt
valgrindCommandLine="$valgrindExec --tool=memcheck --trace-children=yes --track-fds=yes --time-stamp=yes --num-callers=20 --error-exitcode=$valgrindErrorCode --leak-check=full --leak-resolution=med --log-file=$valgrindOut --show-reachable=yes --suppressions=$supressions"

$valgrindCommandLine "$@"
executionResult=$?
echo "[SERCOM] Summary" >> $valgrindOut
echo "[SERCOM] Command Line: $valgrindCommandLine" >> $valgrindOut
echo "[SERCOM] Error code configured for Valgrind: $valgrindErrorCode." >> $valgrindOut
echo "[SERCOM] Valgrind execution result: $executionResult." >> $valgrindOut
if [ $executionResult -eq $valgrindErrorCode ]
then
    echo "[SERCOM] Valgrind result: Failure." >> $valgrindOut
    return 1
else
    echo "[SERCOM] Valgrind result: Success." >> $valgrindOut
    return 0
fi
