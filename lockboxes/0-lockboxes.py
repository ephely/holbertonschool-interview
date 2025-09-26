#!/usr/bin/python3

def canUnlockAll(boxes):
    opened = set([0])
    keys = boxes[0][:]

    while keys:
        key = keys.pop()
        if key < len(boxes) and key not in opened:
            opened.add(key)
            keys.extend(boxes[key])

    return len(opened) == len(boxes)
