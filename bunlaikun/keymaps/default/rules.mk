#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

SRC += features/combo.c

# RGB Matrix is enabled at the revision level,
# while we use the regular RGB underglow for testing
# RGB_MATRIX_ENABLE = no

OLED_ENABLE = yes
RGBLIGHT_ENABLE = yes
WPM_ENABLE = yes
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
ENCODER_ENABLE = yes
