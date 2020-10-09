const { series, parallel } = require('gulp')
const gulp = require('gulp')
const concat = require('gulp-concat')
const uglify = require('gulp-uglify')
const babel = require('gulp-babel')

function padrao(cb){
    gulp.src('src/**/*.js')
        .pipe(babel({
            comments: false,
            presets: ["env"]
        }))
        .pipe(uglify())
        .on('error', err => console.log("erro: " + e))
        .pipe(concat('codigo.min.js'))
        .pipe(gulp.dest('build/js'))

    return cb()
}

function fim(cb){
    console.log('Fim!')
    return cb()
}

// module.exports.default = series(padrao, fim)
module.exports.default = parallel(padrao, fim)