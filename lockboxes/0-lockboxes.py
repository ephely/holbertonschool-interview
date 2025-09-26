#!/usr/bin/python3
"""
Write a method that determines if all the boxes can be opened.
"""

def canUnlockAll(boxes):
    """
    You have n number of locked boxes in front of you. Each box is numbered
    sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
    """
    opened = set([0])
    keys = boxes[0][:]

    while keys:
        key = keys.pop()
        if key < len(boxes) and key not in opened:
            opened.add(key)
            keys.extend(boxes[key])

    return len(opened) == len(boxes)
