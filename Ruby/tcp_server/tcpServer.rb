require 'socket'
server = TCPServer.new 8080

while session = server.accept
  session.puts "Hi m8!It's #{Time.now}"
  session.close
end
