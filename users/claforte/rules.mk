SRC += claforte.c

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  SRC += rgb.c
endif
