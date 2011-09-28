# change_class2.rb
# (C) John Mair (banisterfiend); MIT license

require "rbconfig"
dlext = Config::CONFIG['DLEXT']
require "change_class.#{dlext}"


