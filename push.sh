#!/usr/bin/expect -f
spawn git pull
expect "Username: "
send "DU2027"
send "/r"
expect "Password: "
send "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"
send "/r"
interact
