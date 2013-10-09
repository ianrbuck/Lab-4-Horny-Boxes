#!/usr/bin/env ruby

require 'find'

dirCount = 0
file-count = 0

Find.find(ARGV[0]) do |path|
  if FileTest.directory?(path)
    dirCount += 1
  elsif FileTest.file?(path)
    fileCount += 1
  end
end

printf("Processed all the files from <#{ARGV[0]}>.\n")
printf("There were %d directories.\n", dirCount)
printf("There were %d regular files.\n", fileCount)
