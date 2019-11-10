require 'socket'
require_relative 'request'
require_relative 'response'

server  = TCPServer.new('172.26.11.83', 8080)

loop {
  client  = server.accept
  request = client.readpartial(2048)
  request  = parse(request)
  response = prepare(request)
  puts "#{client.peeraddr[3]} #{request.fetch(:path)} - #{response.code}"
  response.send(client)
  client.close
}
