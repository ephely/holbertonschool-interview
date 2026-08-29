#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];
if (!movieId) {
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(filmUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  fetchCharacter(characters, 0);
});

/**
 * Get and prints the character in the exact order
 * @param {Array} characters - URLs of characters
 * @param {number} index - current character index
 */
function fetchCharacter(characters, index) {
  if (index >= characters.length) {
    return;
  }

  request(characters[index], (error, response, body) => {
    if (error) {
      console.error(error);
      return;
    }

    const characterData = JSON.parse(body);
    console.log(characterData.name);
    fetchCharacter(characters, index + 1);
  });
}
