SERVER_ROOT = "/home/linux/Documents/Web/thing/"

def parse_headers(request)
  headers = {}
  request.lines[1..-1].each do |line|
    return headers if line == "\r\n"
    header, value = line.split
    headers[header] = value
  end
  def normalize(header)
    header.gsub(":", "").downcase.to_sym
  end
end

def prepare(request)
  if request.fetch(:path) == "/"
    respond_with(SERVER_ROOT + "index.html")
  else
    respond_with(SERVER_ROOT + request.fetch(:path))
  end
end

def respond_with(path)
  if File.exists?(path)
    send_ok_response(File.binread(path))
  else
    send_file_not_found
  end
end

def send_ok_response(data)
  Response.new(code: 200, data: data)
end

def send_file_not_found
  Response.new(code: 404)
end

class Response
  def initialize(code:, data: "")
    @response =
    "HTTP/1.1 #{code}\r\n" +
    "Content-Length: #{data.size}\r\n" +
    "\r\n" +
    "#{data}\r\n"
  end

  def code
    return @response[9..11]
  end

  def send(client)
    client.write(@response)
  end
end
