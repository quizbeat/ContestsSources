#!/usr/bin/env ruby
def send_cmd(cmd)
  puts cmd
  STDOUT.flush
end
a = 1
while (true) do
  send_cmd a
  case gets
  when /yes/
    exit if a == 1
    a = 1
  when /no/
    a = rand(1<<31)
  end
end
