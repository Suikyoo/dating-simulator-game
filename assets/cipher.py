
import pygame, sys, pyperclip

pygame.init()


pygame.display.set_mode((1, 1))
img = pygame.image.load(sys.argv[1]).convert()

cipher_data = {
        (255, 255, 255) : u"█",
        (191, 191, 191) : u"▓",
        (128, 128, 128) : u"▒",
        (61, 61, 61) : u"░"
        }

string = ""
for y in range(img.get_height()):
    for x in range(img.get_width()):
        color = img.get_at((x, y))
        tuple_color = (color.r, color.g, color.b)
        string += cipher_data.get(tuple_color, " ");

    string += "\\n"

pyperclip.copy(string)
