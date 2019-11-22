import Router from 'koa-router';
import noteStore from './store';

export const router = new Router();

router.get('/', async (ctx) => {
  const response = ctx.response;
  response.body = await noteStore.find({});
  response.status = 200; // ok
});

router.get('/:id', async (ctx) => {
  const note = await noteStore.findOne({ _id: ctx.params.id });
  const response = ctx.response;
  if (note) {
    response.body = note;
    response.status = 200; // ok
  } else {
    response.status = 404; // not found
  }
});

const createNote = async (note, response) => {
  try {
    response.body = await noteStore.insert(note);
    response.status = 201; // created
  } catch (err) {
    response.body = { issue: [{ error: err.message }] };
    response.status = 400; // bad request
  }
};

router.post('/', async (ctx) => await createNote(ctx.request.body, ctx.response));

router.put('/:id', async (ctx) => {
  const note = ctx.request.body;
  const id = ctx.params.id;
  const noteId = note._id;
  const response = ctx.response;
  if (noteId && noteId !== id) {
    response.body = { issue: [{ error: 'Param id and body _id should be the same' }] };
    response.status = 400; // bad request
    return;
  }
  if (!noteId) {
    await createNote(note, response);
  } else {
    const updatedCount = await noteStore.update({ _id: id }, note);
    if (updatedCount === 1) {
      response.body = note;
      response.status = 200; // ok
    } else {
      response.body = { issue: [{ error: 'Resource no longer exists' }] };
      response.status = 405; // method not allowed
    }
  }
});

router.del('/:id', async (ctx) => {
  await noteStore.remove({ _id: ctx.params.id });
  ctx.response.status = 204; // no content
});
