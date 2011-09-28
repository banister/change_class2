direc = File.dirname(__FILE__)

require 'rubygems'
require "#{direc}/../lib/change_class"
require 'bacon'

puts "Testing change_class version #{ChangeClass::VERSION}..." 
puts "Ruby version: #{RUBY_VERSION}"

describe ChangeClass do
end

