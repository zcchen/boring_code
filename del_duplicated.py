#!/usr/bin/env python
# -*-   encoding : utf8   -*-

'''
This file is used to handle the duplicated SMS restored
from a Android App named "SMS Backup & Restore".
<https://play.google.com/store/apps/details?id=com.riteshsahu.SMSBackupRestore>
'''
"""
If you backup the SMS with this app, and then restore back without wrapping
you phone, you may get duplicated sms.
This script file is written for this situation, and handle the xml on your
computer before, so that it will save your time.
"""

import xml.etree.ElementTree as ET
import hashlib
import sys

def main(xml_file_in, xml_file_out):
    print("Loading xml_file ({}) ...".format(xml_file_in))
    tree = ET.parse(xml_file_in)

    root = tree.getroot()

    _count = root.get('count')
    print("Old SMS coun: {}".format(_count))

    key_dict = {}

    for i in root.findall('./'):
        hash_key = i.get('date') + '_' + \
                hashlib.sha224(i.get('body').encode()).hexdigest()
                #hashlib.md5(i.get('body').encode()).hexdigest()
        try:
            if key_dict[hash_key] == True:
                root.remove(i)
        except KeyError:
            key_dict[hash_key] = True
    new_count = str(len(key_dict))
    root.set('count', new_count)

    print("NEW SMS coun: {}".format(new_count))

    tree.write(xml_file_out)
    print("Done")

__Usage = \
'''python del_duplicated.py <input_xml> <output_xml>
'''

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print(__Usage)
    else:
        main(sys.argv[1], sys.argv[2])
